template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    buffer = new T[i];
    maxSize = i;
    frontIndex = 0;
    backIndex = -1;
    this-> length = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (isEmpty()) {
        throw string("back: error, queue is empty, cannot access the back");
    }
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
    frontIndex = 0;
    backIndex = -1;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
	maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;
    buffer = new T[maxSize];
    for (int i = 0; i < maxSize; i++) {
        buffer[i] = copyObj.buffer[i];
	}
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) {
        throw string("Queue is empty");
    }
    frontIndex = (frontIndex + 1) % maxSize;  // wraps around array
    this->length--;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (isFull()) {
        throw string("Queue is full");
    }
    backIndex = (backIndex + 1) % maxSize; // wraps around array
    buffer[backIndex] = elem;
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    if (isEmpty()) {
        throw string("front: error, queue is empty, cannot access the front");
    }
	return buffer[frontIndex];
    // TODO
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
