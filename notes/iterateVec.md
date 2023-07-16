# vector

## Algorithms

## iterate through vector

C++ 03 Style-- > size

```cpp
for (int i = 0; i < vector.size(); i++) {
  vector[i].doSomething();
}
```

C++ 11 Style-- > iterator

```cpp
for (auto it = begin(vector); it != end(vector); ++it) {
  it->doSomething();
}
```

or

```cpp
for (auto& element : vector) {
  element.doSomething();
}
```

or **preferred**

```cpp
for (std::vector<T>::iterator it = v.begin(); it != v.end(); ++it) {
  it->doSomething();
}
```
