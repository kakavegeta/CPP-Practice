#ifndef LIST_H
#define LIST_H

#include <algorithm>
using namespace std;

template <typename Object>
class List{
    private:
        struct Node{
            Object data;
            Node  *prev;
            Node  *next;

            Node(const Object &d = Object{ }, Node *p = nullptr, Node *n = nullptr)
            : data{d}, prev{p}, next{n} {}

            Node(Object &&d, Node *p = nullptr, Node *n = nulptr)
            : data{std::move(d)}, prev{p}, next{n} {}
        };

    public:
        class const_iterator{
            public:
                const_iterator():current{nullptr} {}

                const Object & operator* () const {return retrieve();}

                const_iterator & operator++ ()
                {current = current->next;
                 return *this;
                }

                const_iterator operation++(int){
                    const_iterator old = *this;
                    ++(*this);
                    return old;
                }

                const_iterator & operator -- ( ){
                    current = current->prev;
                    return *this;
                }

                const_iterator operator -- ( ){
                    const_iterator old = *this;
                    --(*this);
                    return old;
                }

                bool operator== (const const_iterator & rhs) const {
                    return current == rhs.current;
                }

                bool operator!= (const const_iterator & rhs) const {
                    return !(*this==rhs);
                }
            
            protected:
                Node *current;
                Object & retrieve( ) const{return current->data;}
                const_iterator(Node *p): current{p} {}
                friend class List<Object>;

        };
        class iterator: public const_iterator{
            public:
                iterator(){}

                Object & operator*(){
                    return const_iterator::retrieve();
                }
        };
    
    public:
        List( ) {init();}
        ~List () {
            clear();
            delete head;
            delete tail;
        }

        List(const List &rhs){
            init();
            for(auto &x:rhs) push_back(x);
        }

        List & operator= (const List &rhs){
            List copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

        List (List &&rhs)
        : theSize(rhs.theSize), head(rhs.head), tail(rhs.tail)
        {
            rhs.theSize = 0;
            rhs.head = nullptr;
            rhs.tail = nullptr;
        }

        List & operator= (List  && rhs)
        {
            std::swap(theSize, rhs.theSize);
            std::swap(head, rhs.head);
            std::swap(tail, rhs.tail);
            return *this;
        }

        iterator begin()
        {return iterator(head->next);}

        const_iterator begin()
        {return const_iterator(head->next);}
        


    private:
        int theSize;
        Node *head;
        Node *tail;

        void init(){
            theSize = 0;
            head = new Node;
            tail = new Node;
            head->next = tail;
            tail->prev = head;
        }
}




#endif 