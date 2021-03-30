namespace math {
    template <typename T>
    const unsigned int Array2D<T> :: getWidth() const  {
        return this->width;
    }

    template <typename T>
    const unsigned int Array2D<T> :: getHeight() const  {
       return this->height;
    }

    template <typename T>
    T * Array2D<T> :: getRawDataPtr()   {
        return this->buffer;
    }
    
    template <typename T>
    void Array2D<T>::setData(const T * const & data_ptr) {
        if ((width == 0) || (height == 0)) return;
		buffer.resize(width*height);
        if(data_ptr!=nullptr){
            for (int i = 0; i < width*height; i++) {
                buffer[i] = data_ptr[i];
            }
        }else{
            for (int i = 0; i < width*height; i++) {
                buffer[i] = {0,0,0};
            }
        }
    }

    template <typename T>
    Array2D<T>::Array2D(unsigned int width , unsigned int height , const T * data_ptr ){
        this->width = width;
        this->height = height;
		buffer.resize(width*height);
        setData(data_ptr);
    }
    
    template <typename T>
    Array2D<T>::Array2D(const Array2D &src) {
        width = src.getWidth();
        height = src.getHeight();
        buffer = src.buffer;
    }

    template <typename T>
    Array2D<T>::~Array2D() {
        delete &buffer;
    }

    template <typename T>
        Array2D<T> & Array2D<T>:: operator= (const Array2D & right){
            if (&right == this) {
                return *this;
            }
            Array2D i(right);
            return i;
         }


		template <typename T>
		T & Array2D<T>:: operator() (unsigned int x, unsigned int y) {
			return buffer[y][x];
		}
}
