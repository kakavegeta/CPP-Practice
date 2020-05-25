#ifndef _LIST_H
#define _LIST_H

#include <iostream>


namespace algo {

template <typename T>
class List {
    public:
    class const_iterator {
        public:
        const_iterator(): cur{nullptr} {}

        const T& operator* () const {
            return retrive();
        }

        const_iterator& operator++ () {
            cur = cur->next;
            return *this;
        }

        const_iterator operator++ (int) {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        const_iterator& operator-- () {
            cur = cur->prev;
            return *this;
        }

        const_iterator operator-- () {
            const_iterator old = *this;
            --(*this);
            return old;
        }

        bool operator== (const const_iterator& rhs) const {
            return (cur == rhs.cur);
        }

        bool operator!= (const const_iterator& rhs) const {
            return (cur != rhs.cur);
        }

        protected:
        Node* cur;
        T& retrive() const {
            return cur->val;
        }

        const_iterator(Node* p)
            :cur{p} {}
        
        friend class List<T>;
    };

    class iterator: public const_iterator {
        public:
        iterator() {}

        T& operator*() {
            return const_iterator::retrive();
        }

        const T& operator*() const {
            return const_iterator::operator*();
        }

        iterator& operator++() {
            this->cur = this->cur->next;
            return *this;
        }

        iterator operator++ (int) {
            iterator old = *this;
            ++ (*this);
            return old;
        }

        iterator & operator--() {
            this->cur = this->cur->prev;
            return *this;
        }

        iterator operator-- () {
            iterator old = *this;
            -- (*this);
            return old;
        }

        protected:
        iterator(Node* node): const_iterator{node} {}
        
        friend class List<T>;
    };

    public:
    List() {initialize()};
    ~List() {
        clear();
        delete head;
        delete tail;
    }

    List(const List& rhs) {
        initialize();
        for(auto& elem: rhs) {
            push_back(elem);
        }
    }

    List(const List&& rhs)
        :size{rhs.size()}, head{rhs.head}, tail{rhs.tail}
    {
        rhs.size = 0;
        rhs.head = rhs.tail = nullptr;
    }

    List& operator= (const List& rhs) {
        List copy = rhs;
        std::swap(copy, *this);
        return *this;
    }

    List& operator= (List && rhs) {
        std::swap(size, rhs.size());
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        return *this;
    }

    iterator begin() {
        return iterator(head->next);
    }

    const_iterator begin() const {
        return const_iterator(head->next);
    }

    iterator end () {
        return iterator(tail);
    }

    const_iterator end() {
        return const_iterator(tail);
    }

    int size() const {
        return size;
    }

    bool empty() const {
        return (size==0);
    }

    void clear() {
        while(!empty()) {
            pop_front();
        }
    }

    const T& front() const{
        return(*begin());
    }

    T front() {
        return (*begin());
    }

    const T& back() const {
        return (*--end());
    }

    T back() {
        return (*--end());
    }

    void push_front(const T& t) {
        insert(t, begin());
    }

    void push_front(T&& t) {
        insert(std::move(t), begin());
    }

    void push_back(const T& t) {
        insert(t, end());
    }

    void push_back(T&& t) {
        insert(std::move(t), end());
    }

    void pop_front() {
        erase(begin());
    }

    void pop_back() {
        erase(--end());
    }

    iterator insert(const T& t, iterator it) {
        Node* cur = it.cur;
        Node* node = Node(t, cur->prev, cur);
        cur->prev->next = node;
        cur->prev = node;
        ++size;
        return iterator(node);
    }

    iterator erase(iterator it) {
        Node* cur = it.cur;
        iterator retit(cur->next);
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        --size;
        return retit;
    }

    iterator erase(iterator from, iterator to) {
        for(iterator it = from; it!=to;) {
            it = erase(it);
        }
        return to;
    }

    private:

    int size;
    Node* head;
    Node* tail;

    void initialize(){
        size = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

    class Node {
        public:
        Node (const T& t = T{}, Node* pprev = nullptr, Node* pnext = nullptr)
            : val{t}, prev{pprev}, next{pnext} {}
        Node (const T&& t)
            : val{std::move(t)}, prev{nullptr}, next{nullptr} {}

        private:
        T val;
        Node* prev;
        Node* next;
        friend class List<T>;
    };



}



}