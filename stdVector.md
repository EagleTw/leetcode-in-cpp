# std::vecotr     
     
     
## iterate through vector     
     
C++03 Style    
```    
for(int i=0; i < vector.size(); i++){    
   vector[i].doSomething();    
}    
```    
     
C++11 Style
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

**preferred**
```
for(std::vector<T>::iterator it = v.begin(); it != v.end(); ++it) {
    it->doSomething();
}
```
