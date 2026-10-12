#include <iostream>
#include <string>
#include <array>

//stack needs pop, push, peek
//queue needs enqueue, dequque, peek
//deque needs everything
//all functions need isempty and size

//node struct for ll varients

struct Node {
    int value;
    Node* next;
    Node* prev;
};

//array stack

class a_stack {
    int max;
    int length;
    int *array;
    public:

    a_stack(int max_length) {
        max = max_length;
        length = 0;
        array = new int[max_length];
    }

    bool Push(int item) {
        if(length >= max) {
            return false;
        } else {
            array[length] = item;
            length++;
            return true;
        }
    }

    int Pop() {
        if(length == 0) {
            return -1;
        }
        length--;
        return array[length];
    }

    int Peek() {
        if(length == 0) {
            return -1;
        }
        return array[length - 1];
    }

    bool isEmpty() {
        return length == 0;
    }

    int getLength() {
        return length;
    }

};

class ll_stack {
    Node* top;
    int length;
    
    public:

    ll_stack() {
        top = nullptr;
        length = 0;
    }

    bool Push(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = top;
        newNode->prev = nullptr;
        top = newNode;
        length++;
        return true;
    }

    int Pop() {
        if(top == nullptr) {
            return -1;
        }
        Node* temp = top;
        int value = temp->value;
        top = top->next;
        delete temp;
        length--;
        return value;
    }

    int Peek() {
        if(top == nullptr) {
            return -1;
        }
        return top->value;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int getLength() {
        return length;
    }

};

class a_queue {
    int max;
    int length;
    int front;
    int *array;
    public:

    a_queue(int max_length) {
        max = max_length;
        length = 0;
        front = 0;
        array = new int[max_length];
    }

    bool Enqueue(int item) {
        if(length >= max) {
            return false;
        } else {
            array[(front + length) % max] = item;
            length++;
            return true;
        }
    }

    int Dequeue() {
        if(length == 0) {
            return -1;
        }
        int value = array[front];
        front = (front + 1) % max;
        length--;
        return value;
    }

    int Peek() {
        if(length == 0) {
            return -1;
        }
        return array[front];
    }

    bool isEmpty() {
        return length == 0;
    }

    int getLength() {
        return length;
    }

};

class ll_queue {
    Node* head;
    Node* tail;
    int length;

    public:

    ll_queue() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    bool Enqueue(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;
        newNode->prev = tail;
        if(tail == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        length++;
        return true;
    }

    int Dequeue() {
        if(head == nullptr) {
            return -1;
        }
        Node* temp = head;
        int value = temp->value;
        head = head->next;
        if(head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete temp;
        length--;
        return value;
    }

    int Peek() {
        if(head == nullptr) {
            return -1;
        }
        return head->value;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int getLength() {
        return length;
    }

};

class a_deque {
    int max;
    int length;
    int front;
    int *array;
    public:

    a_deque(int max_length) {
        max = max_length;
        length = 0;
        front = 0;
        array = new int[max_length];
    }

    bool PushFront(int item) {
        if(length >= max) {
            return false;
        } else {
            front = (front - 1 + max) % max;
            array[front] = item;
            length++;
            return true;
        }
    }

    bool PushBack(int item) {
        if(length >= max) {
            return false;
        } else {
            array[(front + length) % max] = item;
            length++;
            return true;
        }
    }

    int PopFront() {
        if(length == 0) {
            return -1;
        }
        int value = array[front];
        front = (front + 1) % max;
        length--;
        return value;
    }

    int PopBack() {
        if(length == 0) {
            return -1;
        }
        length--;
        return array[(front + length) % max];
    }

    int PeekFront() {
        if(length == 0) {
            return -1;
        }
        return array[front];
    }

    int PeekBack() {
        if(length == 0) {
            return -1;
        }
        return array[(front + length - 1) % max];
    }

    bool isEmpty() {
        return length == 0;
    }

    int getLength() {
        return length;
    }

};

class ll_deque {
    Node* head;
    Node* tail;
    int length;

    public:

    ll_deque() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    bool PushFront(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->prev = nullptr;
        newNode->next = head;
        if(head == nullptr) {
            tail = newNode;
        } else {
            head->prev = newNode;
        }
        head = newNode;
        length++;
        return true;
    }

    bool PushBack(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;
        newNode->prev = tail;
        if(tail == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        length++;
        return true;
    }

    int PopFront() {
        if(head == nullptr) {
            return -1;
        }
        Node* temp = head;
        int value = temp->value;
        head = head->next;
        if(head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete temp;
        length--;
        return value;
    }

    int PopBack() {
        if(tail == nullptr) {
            return -1;
        }
        Node* temp = tail;
        int value = temp->value;
        tail = tail->prev;
        if(tail == nullptr) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }
        delete temp;
        length--;
        return value;
    }

    int PeekFront() {
        if(head == nullptr) {
            return -1;
        }
        return head->value;
    }

    int PeekBack() {
        if(tail == nullptr) {
            return -1;
        }
        return tail->value;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int getLength() {
        return length;
    }

};


int main() {
    std::cout << "----- a_stack -----" << std::endl;
    a_stack s1(4);
    std::cout << "isEmpty: " << s1.isEmpty() << std::endl;
    std::cout << "Pop on empty: " << s1.Pop() << std::endl;
    std::cout << "Peek on empty: " << s1.Peek() << std::endl;
    for(int i = 1; i <= 5; i++) {
        std::cout << "Push " << i * 10 << ": " << s1.Push(i * 10) << std::endl;
    }
    std::cout << "Peek: " << s1.Peek() << std::endl;
    std::cout << "size: " << s1.getLength() << std::endl;
    while(!s1.isEmpty()) {
        std::cout << "Pop: " << s1.Pop() << std::endl;
    }
    std::cout << "Pop on empty: " << s1.Pop() << std::endl;
    std::cout << "isEmpty: " << s1.isEmpty() << std::endl;

    std::cout << std::endl << "----- ll_stack -----" << std::endl;
    ll_stack s2;
    std::cout << "isEmpty: " << s2.isEmpty() << std::endl;
    std::cout << "Pop on empty: " << s2.Pop() << std::endl;
    std::cout << "Peek on empty: " << s2.Peek() << std::endl;
    for(int i = 1; i <= 5; i++) {
        std::cout << "Push " << i * 10 << ": " << s2.Push(i * 10) << std::endl;
    }
    std::cout << "Peek: " << s2.Peek() << std::endl;
    std::cout << "size: " << s2.getLength() << std::endl;
    while(!s2.isEmpty()) {
        std::cout << "Pop: " << s2.Pop() << std::endl;
    }
    std::cout << "Pop on empty: " << s2.Pop() << std::endl;
    std::cout << "isEmpty: " << s2.isEmpty() << std::endl;

    std::cout << std::endl << "----- a_queue -----" << std::endl;
    a_queue q1(4);
    std::cout << "isEmpty: " << q1.isEmpty() << std::endl;
    std::cout << "Dequeue on empty: " << q1.Dequeue() << std::endl;
    std::cout << "Peek on empty: " << q1.Peek() << std::endl;
    for(int i = 1; i <= 5; i++) {
        std::cout << "Enqueue " << i * 10 << ": " << q1.Enqueue(i * 10) << std::endl;
    }
    std::cout << "Dequeue: " << q1.Dequeue() << std::endl;
    std::cout << "Dequeue: " << q1.Dequeue() << std::endl;
    std::cout << "Enqueue 60: " << q1.Enqueue(60) << std::endl;
    std::cout << "Enqueue 70: " << q1.Enqueue(70) << std::endl;
    std::cout << "Peek: " << q1.Peek() << std::endl;
    std::cout << "size: " << q1.getLength() << std::endl;
    while(!q1.isEmpty()) {
        std::cout << "Dequeue: " << q1.Dequeue() << std::endl;
    }
    std::cout << "Dequeue on empty: " << q1.Dequeue() << std::endl;
    std::cout << "isEmpty: " << q1.isEmpty() << std::endl;

    std::cout << std::endl << "----- ll_queue -----" << std::endl;
    ll_queue q2;
    std::cout << "isEmpty: " << q2.isEmpty() << std::endl;
    std::cout << "Dequeue on empty: " << q2.Dequeue() << std::endl;
    std::cout << "Peek on empty: " << q2.Peek() << std::endl;
    for(int i = 1; i <= 5; i++) {
        std::cout << "Enqueue " << i * 10 << ": " << q2.Enqueue(i * 10) << std::endl;
    }
    std::cout << "Dequeue: " << q2.Dequeue() << std::endl;
    std::cout << "Dequeue: " << q2.Dequeue() << std::endl;
    std::cout << "Enqueue 60: " << q2.Enqueue(60) << std::endl;
    std::cout << "Peek: " << q2.Peek() << std::endl;
    std::cout << "size: " << q2.getLength() << std::endl;
    while(!q2.isEmpty()) {
        std::cout << "Dequeue: " << q2.Dequeue() << std::endl;
    }
    std::cout << "Dequeue on empty: " << q2.Dequeue() << std::endl;
    std::cout << "isEmpty: " << q2.isEmpty() << std::endl;

    std::cout << std::endl << "----- a_deque -----" << std::endl;
    a_deque d1(4);
    std::cout << "isEmpty: " << d1.isEmpty() << std::endl;
    std::cout << "PopFront on empty: " << d1.PopFront() << std::endl;
    std::cout << "PopBack on empty: " << d1.PopBack() << std::endl;
    std::cout << "PushBack 20: " << d1.PushBack(20) << std::endl;
    std::cout << "PushFront 10: " << d1.PushFront(10) << std::endl;
    std::cout << "PushBack 30: " << d1.PushBack(30) << std::endl;
    std::cout << "PushFront 5: " << d1.PushFront(5) << std::endl;
    std::cout << "PushBack 40: " << d1.PushBack(40) << std::endl;
    std::cout << "PeekFront: " << d1.PeekFront() << " PeekBack: " << d1.PeekBack() << std::endl;
    std::cout << "size: " << d1.getLength() << std::endl;
    std::cout << "PopFront: " << d1.PopFront() << std::endl;
    std::cout << "PopBack: " << d1.PopBack() << std::endl;
    std::cout << "PopFront: " << d1.PopFront() << std::endl;
    std::cout << "PopBack: " << d1.PopBack() << std::endl;
    std::cout << "PopFront on empty: " << d1.PopFront() << std::endl;
    std::cout << "isEmpty: " << d1.isEmpty() << std::endl;

    std::cout << std::endl << "----- ll_deque -----" << std::endl;
    ll_deque d2;
    std::cout << "isEmpty: " << d2.isEmpty() << std::endl;
    std::cout << "PopFront on empty: " << d2.PopFront() << std::endl;
    std::cout << "PopBack on empty: " << d2.PopBack() << std::endl;
    std::cout << "PushBack 20: " << d2.PushBack(20) << std::endl;
    std::cout << "PushFront 10: " << d2.PushFront(10) << std::endl;
    std::cout << "PushBack 30: " << d2.PushBack(30) << std::endl;
    std::cout << "PushFront 5: " << d2.PushFront(5) << std::endl;
    std::cout << "PushBack 40: " << d2.PushBack(40) << std::endl;
    std::cout << "PeekFront: " << d2.PeekFront() << " PeekBack: " << d2.PeekBack() << std::endl;
    std::cout << "size: " << d2.getLength() << std::endl;
    std::cout << "PopFront: " << d2.PopFront() << std::endl;
    std::cout << "PopBack: " << d2.PopBack() << std::endl;
    std::cout << "PopFront: " << d2.PopFront() << std::endl;
    std::cout << "PopBack: " << d2.PopBack() << std::endl;
    std::cout << "PopFront: " << d2.PopFront() << std::endl;
    std::cout << "PopBack on empty: " << d2.PopBack() << std::endl;
    std::cout << "isEmpty: " << d2.isEmpty() << std::endl;

    return 0;
}