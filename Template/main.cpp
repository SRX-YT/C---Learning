#include <iostream>

//2. ВЫВЕДЕНИЕ ТИПОВ ШАБЛОННЫХ АРГУМЕНТОВ
template<typename T>
T max (T a, T b) {
    return (a >= b ? a : b);
}

/*
int max (int a, int b) -> max<int>(a, b); || max(a, b);
char max (char a, char b) -> max<char>(aChar, bChar); || max(aChar, bChar);
*/

//3. ШАБЛОНЫ КЛАССОВ
template<typename T>
class Interval {
public:
    Interval(T inStart, T inEnd) : start(inStart), end(inEnd) {}

    T getStart() const { return start; }
    T getEnd() const { return end; }
    T getSize() const { return (end - start); }

    Interval<T> intersection(const Interval<T>& inOther) const {
        return Interval<T> {
            max(start, inOther.start),
            std::min(end, inOther.end)
        };
    }

private:
    T start;
    T end;
};

// 4. СПЕЦИАЛИЗАЦИИ
template<typename T>
class SimpleArray {
public:
    SimpleArray(int inElementsNum) : elements(new T[inElementsNum]), num(inElementsNum) {}

    int getNum() const { return num; }
    T getElement(int inIndex) const {
        return elements[inIndex];
    }
    void setElement(int inIndex, T inValue) {
        elements[inIndex] = inValue;
    }

    ~SimpleArray() { delete[] elements; }

private:
    T* elements = nullptr;
    int num = 0;
};

struct BitArrayAccessData {
    int byteIndex = 0;
    int bitIndexInByte = 0;
};

template<>
class SimpleArray<bool> {
public:
    SimpleArray(int inElementsNum) : elementsMemory(nullptr), num(inElementsNum) {
        const int lastIndex = (inElementsNum - 1);
        const BitArrayAccessData lastElementAccessData = getAccessData(lastIndex);

        const int neededBytesNum = lastElementAccessData.byteIndex + 1;
        elementsMemory = new unsigned char[neededBytesNum];
    }

    int getNum() const { return num; }
    bool getElement(int inIndex) const {
        const BitArrayAccessData accessData = getAccessData(inIndex);
        const unsigned char elementMask = (1 << accessData.bitIndexInByte);
        return elementsMemory[accessData.byteIndex] & elementMask;
    }

    void setElement(int inIndex, bool inValue) const {
        const BitArrayAccessData accessData = getAccessData(inIndex);

        const unsigned char elementMask = (1 << accessData.bitIndexInByte);
        elementsMemory[accessData.byteIndex] = (elementsMemory[accessData.byteIndex] & ~elementMask) | (inValue ? elementMask : 0);
    }

    ~SimpleArray() {
        delete[] elementsMemory;
    }
private:
    static BitArrayAccessData getAccessData(int inElementIndex) {
        BitArrayAccessData result;
        result.byteIndex = inElementIndex / 8;
        result.bitIndexInByte = inElementIndex - result.byteIndex * 8;
        return result;
    }

    unsigned char* elementsMemory = nullptr;
    int num = 0;
};

// НЕСКОЛЬКО ШАБЛОННЫХ АРГУМЕНТОВ
template<typename KeyType, typename ValueType>
struct KeyAndValue {
    KeyType key;
    ValueType value;
};

template<typename KeyType, typename ValueType>
class Dictionary {
public:
    Dictionary(int inCapacity) : keysAndValues(new KeyAndValue<KeyType, ValueType>[inCapacity]), capacity(inCapacity), num(0) {}

    const ValueType* getValue(KeyType inKey) const {
        const KeyAndValue<KeyType, ValueType>* foundKeyAndValue = findPair(inKey);
        return foundKeyAndValue ? &foundKeyAndValue-> value : nullptr;
    }

    void setValue(KeyType inKey, ValueType inValueType) {
        KeyAndValue<KeyType, ValueType>* keyAndValueToSet = findPair(inKey);

        if (!keyAndValueToSet) {
            if (num == capacity) return;
            keyAndValueToSet = &keysAndValues[num];
            keyAndValueToSet->key = inKey;
            ++num;
        }

        keyAndValueToSet->value = inValueType;
    }

    ~Dictionary() {
        delete[] keysAndValues;
    }

private:
    const KeyAndValue<KeyType, ValueType>* findPair(KeyType inKey) const {
        for (int i = 0; i < num; ++i) {
            if (keysAndValues[i].key == inKey) {
                return &keysAndValues[i];
            }
        }

        return nullptr;
    }

    KeyAndValue<KeyType, ValueType>* findPair(KeyType inKey) {
        const Dictionary<KeyType, ValueType>* constThis = const_cast<const Dictionary<KeyType, ValueType>*>(this);
        const KeyAndValue<KeyType, ValueType>* constResult = constThis->findPair(inKey);
        return const_cast<KeyAndValue<KeyType, ValueType>*>(constResult);
    }

    KeyAndValue<KeyType, ValueType>* keysAndValues = nullptr;
    int capacity = 0;
    int num = 0;
};

// 7. ШАБЛОННЫЕ АРГУМЕНТЫ КОНСТАНТЫ
template<int Value>
int getFactorial(){
    return Value * getFactorial<Value - 1>();
}

template<>
int getFactorial<1>(){ return 1; }

// 8. ПЕРЕДАЧА ШАБЛОННЫХ АРГУМЕНТОВ В ШАБЛОННОМ КОНТЕКСТЕ
int getMaxElement(const SimpleArray<int>& inArray) {
    int maxElement = inArray.getElement(0);
    for (int i = 1; i < inArray.getNum(); ++i) {
        maxElement = max(maxElement, inArray.getElement(i));
    }

    return maxElement;
}

int main() {
    int a = 3, b = 2, c = 1;
    int abMax = max<int>(a, b);
    const int test1 = max(abMax, c);

    char aChar = 56, bChar = 31, cChar = 75;
    char abMaxChar = max<char>(aChar, bChar);
    const char test2 = max(abMaxChar, cChar);

    a = 1;
    bChar = 'b';
    const int test3 = max<int>(a, bChar);

    const Interval<int> intervalA{1, 3};
    const Interval<int> intervalB{2, 4};
    const Interval<int> intersection{intervalA.intersection(intervalB)};
    const int intersectionSize = intersection.getSize();

    const Interval<char> intervalBChar{'a', 'c'};
    const Interval<char> intervalAChar{'n', 'd'};
    const Interval<char> intersectionChar{intervalAChar.intersection(intervalBChar)};
    const int intersectionSizeChar = intersectionChar.getSize();

    SimpleArray<int> simpleArray{4};
    simpleArray.setElement(0, 1);
    simpleArray.setElement(1, 2);
    simpleArray.setElement(2, 3);
    simpleArray.setElement(3, 4);
    int sum = 0;
    for (int i = 0; i < simpleArray.getNum(); ++i) {
        sum += simpleArray.getElement(i);
    }

    SimpleArray<bool> simpleBoolArray{8};
    simpleBoolArray.setElement(0, true);
    simpleBoolArray.setElement(1, false);
    simpleBoolArray.setElement(2, false);
    simpleBoolArray.setElement(3, true);
    simpleBoolArray.setElement(4, true);
    simpleBoolArray.setElement(5, false);
    simpleBoolArray.setElement(6, false);
    simpleBoolArray.setElement(7, true);

    Dictionary<int, bool> dictionary{2};
    dictionary.setValue(1, false);
    dictionary.setValue(3, true);

    std::cout << test1 << "\n";
    std::cout << test2 << "\n";
    std::cout << test3 << "\n";
    std::cout << intersectionSize << "\n";
    std::cout << intersectionSizeChar << "\n";
    std::cout << sum << "\n";
    std::cout << simpleBoolArray.getNum() << "\n";
    std::cout << dictionary.getValue(1) << "\n";
    std::cout << dictionary.getValue(2) << "\n";
    std::cout << dictionary.getValue(3) << "\n";
    std::cout << getFactorial<4>() << "\n";

    return 0;
}