#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> elements;

    public:
        void addElement(int element);
        void removeElement(int element);
        int size() const;
        int &operator[](int index);
        bool operator!=(const MagicalContainer &other) const;

        class AscendingIterator
        {
        private:
            const MagicalContainer &container;
            vector<unsigned long> indexes;
            unsigned long index;
            void initIndexes();

        public:
            AscendingIterator(const MagicalContainer &container);
            AscendingIterator(const MagicalContainer &container, unsigned long index);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();

            // For tidy
            AscendingIterator(AscendingIterator &&other) noexcept;
            AscendingIterator &operator=(AscendingIterator &&other) noexcept;

            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            int operator*() const;
            AscendingIterator &operator++();
            AscendingIterator begin();
            AscendingIterator end();
        };
        class SideCrossIterator
        {
        private:
            const MagicalContainer &container;
            vector<unsigned long> indexes;
            unsigned long index;
            void initIndexes();

        public:
            SideCrossIterator(const MagicalContainer &container);
            SideCrossIterator(const MagicalContainer &container, unsigned long index);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator();

            // for tidy to pass
            SideCrossIterator(SideCrossIterator &&other) noexcept;
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;

            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            int operator*() const;
            SideCrossIterator &operator++();
            SideCrossIterator begin();
            SideCrossIterator end();
        };
        class PrimeIterator
        {
        private:
            const MagicalContainer &container;
            vector<unsigned long> indexes;
            unsigned long index;
            bool isPrime(int n) const;
            void initIndexes();

        public:
            PrimeIterator(const MagicalContainer &container);
            PrimeIterator(const MagicalContainer &container, unsigned long index);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();

            // for tidy to pass
            PrimeIterator(PrimeIterator &&other) noexcept;
            PrimeIterator &operator=(PrimeIterator &&other) noexcept;

            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            int operator*() const;
            PrimeIterator &operator++();
            // static PrimeIterator begin(const MagicalContainer &container);
            // static PrimeIterator end(const MagicalContainer &container);
            PrimeIterator begin();
            PrimeIterator end();
        };
    };
}

#endif
