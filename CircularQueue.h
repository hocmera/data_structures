// Copyright (c) 2019 HocMera
// Distributed under the GPL software license
// Implementation of a generic circular queue

template <class T>
class CircularQueue 
{
    private:
    size_t queuesize, avlqueuespace;
    int rd_ptr, wr_ptr;
    T* queue;

    public:
    CircularQueue(size_t queuesize);
    bool EnQeue (const T data);
    bool DeQeueu(T &data);
    size_t AvlQueueSpace();
    ~CircularQueue();
};

template <class T>
CircularQueue<T>::CircularQueue(size_t q_size)
{
    queue = new T[q_size];
	queuesize = q_size;
	avlqueuespace = q_size;
    rd_ptr = wr_ptr =-1;
};

template <class T>
bool CircularQueue<T>::EnQeue(const T data)
{
    if (avlqueuespace!=0){
		wr_ptr = (wr_ptr+1) % this->queuesize;
        this->queue[wr_ptr] = data;
        avlqueuespace-=1;
        return true;
    }
    return false;
};

template <class T>
bool CircularQueue<T>::DeQeueu(T &data)
{
    if (avlqueuespace!=queuesize){
        rd_ptr = (rd_ptr+1) % this->queuesize;
        data = this->queue[rd_ptr];
        avlqueuespace+=1;
        return true;
    }
    return false;
};

template <class T>
size_t CircularQueue<T>::AvlQueueSpace()
{
    return this->avlqueuespace;
}

template <class T>
CircularQueue<T>::~CircularQueue()
{
    delete [] this->queue;
}


