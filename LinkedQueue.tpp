template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    head = nullptr;
    last = nullptr;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    head = nullptr;
    last = nullptr;
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if (last == nullptr) {
        throw string("queue is empty");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    last = nullptr;
} // maybe dequeue until empty?

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    head = nullptr;
    last = nullptr;
    if (copyObj.head == nullptr) {
        return;
    }
    Node * obj = copyObj.head;

    while (obj != nullptr) {
        enqueue(obj->value);
        obj = obj->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        last = nullptr;
    }
    delete temp;
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node* newNode = new Node(elem);
    if (head == nullptr) {
        head = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (head == nullptr) {
        throw string("front(): queue is empty");
    }
    return head->value;

}

template <typename T>
int LinkedQueue<T>::getLength() const {
    int len = 0;
    Node* temp = head;
    while (temp != nullptr) {
        len++;
        temp = temp->next;
    }
    return len;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return head == nullptr;
}
