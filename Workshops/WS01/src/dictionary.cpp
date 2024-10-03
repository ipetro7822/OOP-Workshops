#include "dictionary.h"

namespace seneca
{
    PartOfSpeech Dictionary::parsePartOfSpeech(const std::string &pos_str) const
    {
        if (pos_str == "n." || pos_str == "n. pl.")
            return PartOfSpeech::Noun;
        if (pos_str == "pron.")
            return PartOfSpeech::Pronoun;
        if (pos_str == "a.")
            return PartOfSpeech::Adjective;
        if (pos_str == "adv.")
            return PartOfSpeech::Adverb;
        if (pos_str == "v." || pos_str == "v. i." || pos_str == "v. t." || pos_str == "v. t. & i.")
            return PartOfSpeech::Verb;
        if (pos_str == "prep.")
            return PartOfSpeech::Preposition;
        if (pos_str == "conj.")
            return PartOfSpeech::Conjunction;
        if (pos_str == "interj.")
            return PartOfSpeech::Interjection;
        return PartOfSpeech::Unknown;
    }

    void Dictionary::resize()
    {
        m_numWords = (m_numWords == 0) ? 1 : m_numWords * 2;
        Word *new_array = new Word[m_numWords];

        for (int i = 0; i < m_size; ++i)
        {
            new_array[i] = m_words[i];
        }

        delete[] m_words;
        m_words = new_array;
    }

    std::string Dictionary::partOfSpeechToString(PartOfSpeech pos) const
    {
        switch (pos)
        {
        case PartOfSpeech::Noun:
            return "noun";
        case PartOfSpeech::Pronoun:
            return "pronoun";
        case PartOfSpeech::Adjective:
            return "adjective";
        case PartOfSpeech::Adverb:
            return "adverb";
        case PartOfSpeech::Verb:
            return "verb";
        case PartOfSpeech::Preposition:
            return "preposition";
        case PartOfSpeech::Conjunction:
            return "conjunction";
        case PartOfSpeech::Interjection:
            return "interjection";
        default:
            return "";
        }
    }

    // Default constructor
    Dictionary::Dictionary() = default;

    // Constructor
    Dictionary::Dictionary(const char *filename)
    {
        std::ifstream file(filename);
        if (!file)
        {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line))
        {
            if (m_size == m_numWords)
            {
                resize();
            }

            std::istringstream iss(line);
            std::string word, pos_str, definition;

            std::getline(iss, word, ',');
            std::getline(iss, pos_str, ',');
            std::getline(iss, definition);

            m_words[m_size].m_word = word;
            m_words[m_size].m_pos = parsePartOfSpeech(pos_str);
            m_words[m_size].m_definition = definition;
            ++m_size;
        }
    }

    // Copy constructor
    Dictionary::Dictionary(const Dictionary &other) : m_size(other.m_size), m_numWords(other.m_numWords)
    {
        if (other.m_words)
        {
            m_words = new Word[m_numWords];
            for (int i = 0; i < m_size; ++i)
            {
                m_words[i] = other.m_words[i];
            }
        }
    }

    // Copy assignment
    Dictionary &Dictionary::operator=(const Dictionary &other)
    {
        if (this != &other)
        {
            delete[] m_words;
            m_size = other.m_size;
            m_numWords = other.m_numWords;
            if (other.m_words)
            {
                m_words = new Word[m_numWords];
                for (int i = 0; i < m_size; ++i)
                {
                    m_words[i] = other.m_words[i];
                }
            }
            else
            {
                m_words = nullptr;
            }
        }
        return *this;
    }
    
    // Move constructor
    Dictionary::Dictionary(Dictionary &&other) noexcept
        : m_words(other.m_words), m_size(other.m_size), m_numWords(other.m_numWords)
    {
        other.m_words = nullptr;
        other.m_size = 0;
        other.m_numWords = 0;
    }
    
    // Move assignment
    Dictionary &Dictionary::operator=(Dictionary &&other) noexcept
    {
        if (this != &other)
        {
            delete[] m_words;
            m_words = other.m_words;
            m_size = other.m_size;
            m_numWords = other.m_numWords;
            other.m_words = nullptr;
            other.m_size = 0;
            other.m_numWords = 0;
        }
        return *this;
    }

    // Destructor
    Dictionary::~Dictionary()
    {
        delete[] m_words;
    }

    void Dictionary::searchWord(const char *word) const
    {
        bool found = false;
        std::string wordSpace(strlen(word), ' ');
        bool isFirstDefinition = true;

        for (int i = 0; i < m_size; ++i)
        {
            if (m_words[i].m_word == word)
            {
                found = true;

                if (isFirstDefinition)
                {
                    std::cout << m_words[i].m_word << " - ";
                    isFirstDefinition = false;
                }
                else
                    std::cout << wordSpace << " - ";

                if (seneca::g_settings.m_verbose && m_words[i].m_pos != PartOfSpeech::Unknown)
                    std::cout << "(" << partOfSpeechToString(m_words[i].m_pos) << ") ";

                std::cout << m_words[i].m_definition << std::endl;

                if (!seneca::g_settings.m_show_all)
                    return;
            }
        }

        if (!found)
        {
            std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
        }
    }
} // namespace seneca