# std::vecotr     
     
     
## iterate through vector     
     
Cpp 95 Style    
```    
for(int i=0; i < vector.size(); i++){    
   vector[i].doSomething();    
}    
```    
     
C++11
```    
for (auto it = begin (vector); it != end (vector); ++it) {    
    it->doSomething ();    
}    
```    
or    
```    
for (auto & element : vector) {    
    element.doSomething ();    
}    
```
or 
```
for(std::vector<T>::iterator it = v.begin(); it != v.end(); ++it) {
    it->doSomething();
}
```
