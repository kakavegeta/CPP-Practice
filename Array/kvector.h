#ifndef CPP_PRACTICE_ARRAY_H
#define CPP_PRACTICE_ARRAY_H

namespace  kv{
    static const int kMinCapacity = 16;
    static const int kGrowthFactor = 2;
    static const int kShrinkFactor = 4;

    class KVector{
        public:
            KVector(int capacity);
            KVector(const KVector &other) = default;
            ~KVector;
            int GetSize() const;
            bool IsEmpty() const;
            int GetCapacity() const;
            void DebugString() const;
            int GetValueAt(int index) const;
            int Pop();
            void Insert(int index, int value);
            void PushBack(int value);
            void Prepend(int value);
            void Delete(int index);
            void Remove(int value);
            int Find(int value) const;
        private:
            int capacity_{kMinCapacity};
            int size_{0};
            std::unique_ptr<int[]> data_;
            int DetermineCapacity(int new_capacity) const;
            void Resize(int new_size);
            void IncreaseSize();
            void DecreaseSize();
    };
}
#endif