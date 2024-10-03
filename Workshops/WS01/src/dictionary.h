#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "event.h"

namespace seneca
{
    enum class PartOfSpeech
    {
        Unknown,
        Noun,
        Pronoun,
        Adjective,
        Adverb,
        Verb,
        Preposition,
        Conjunction,
        Interjection
    };
    struct Word
    {
        std::string m_word;
        std::string m_definition;
        PartOfSpeech m_pos = PartOfSpeech::Unknown;
    };

    class Dictionary
    {
        Word *m_words = nullptr; // Dynamic array of words
        int m_size = 0;       // Number of words in the dictionary
        int m_numWords = 0;   // Capacity of the dynamic array

        PartOfSpeech parsePartOfSpeech(const std::string &pos_str) const;

        void resize();

        std::string partOfSpeechToString(PartOfSpeech pos) const;

    public:
        // Default constructor
        Dictionary();

        // Constructor
        Dictionary(const char *filename);


        // Copy constructor
        Dictionary(const Dictionary &other);

        // Copy assignment
        Dictionary &operator=(const Dictionary &other);
        // Move constructor
        Dictionary(Dictionary &&other) noexcept;

        // Move assignment
        Dictionary &operator=(Dictionary &&other) noexcept;

        // Destructor
        ~Dictionary();

        void searchWord(const char *word) const;
    };

} // namespace seneca

#endif // SENECA_DICTIONARY_H
