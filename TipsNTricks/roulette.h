//
//  roulette.h
//  11Test
//
//  Created by Dat Nguyen on 21/10/2014.
//  Copyright (c) 2014 Dat Nguyen. All rights reserved.
//

#pragma once
#include <vector>
#include <stdlib.h>
#include <time.h>

class Data {
public:
    Data() {
        const char* tasks[] = {
			"Abstract Factory"
			, "Builder"
			, "Prototype"
			, "Singleton"
			, "Adapter"
			, "Bridge"
			, "Composite"
			, "Decorator"
			, "Facade"
			, "Flyweight"
			, "Proxy"
			, "Chain of responsibilities"
			, "Command"
			, "Interpreter"
			, "Mediator"
			, "Memento"
			, "Oberver"
			, "Strategy"
			, "Template Method"
			, "Visitor"
			, "Address of idiom"
			, "Attach by initialization idiom"
			, "Attorney-CLient idiom"
			, "Barton-Nackman trick idiom"
			, "Base-From-Member idiom"
			, "Calling Virtuals During Initialization"
			, "Capability Query"
			, "Checked Delete"
			, "Clear-and-Minimize"
			, "Coercion by Member template"
			, "Computational Constructor"
			, "Concrete Data"
			, "Construct on first use"
			, "Construction tracker"
			, "Copy-and-swap"
			, "Copy-on-write"
			, "Intrusive reference counting"
			, "Curiously Recurring Template Patter"
			, "Empty Base Optimization"
			, "enable-if"
			, "Envelope Letter"
			, "Erase-Remove"
			, "Execute-Around pointer"
			, "Expression Template idiom"
			, "Final Class"
			, "Free Function Allocators"
			, "Generic Container Idiom"
			, "Inner Class idiom"
			, "Int-to-type idiom"
			, "Iterator pair idiom"
			, "Making new friends idiom"
			, "Metafunction idiom"
			, "Multi-statement macro idion"
			, "Member detector"
			, "Named Constructor idiom"
			, "Named loop idiom"
			, "Named parameter"
			, "Nifty Counter"
			, "Non-copyable"
			, "Non-Virtual Interface idiom"
			, "Object Generator"
			, "Requiring Heap-Based Objects"
			, "Resource Acquisition Is Initialization idiom"
			, "Resource Return Idiom"
			, "Return Type Resolver idiom"
			, "Scope Guard idiom"
			, "Substitution Failure is not and error (SFINAE)"
			, "Shrink to fit"
			, "Temporary Base Class"
			, "Temporary Proxy"
			, "Thin Template idiom"
			, "Type Generator idiom"
			, "Type safe enum"
			, "Type Selection"
			, "Virtual Constructor idiom"
			, "Virtual Friend Function"
			, "Non copyable (look in RAII for example)"
			, "http://stackoverflow.com/questions/3220009/is-this-key-oriented-access-protection-pattern-a-known-idiom"
			, "Future and Promise"
			, "async"
			, "Monitor pattern"
			, "move constructor and assignment"
			, "Concurrent<T> similar to Monitor<T> but with message queue instead of Mutex"
			, "write your own make_unique"
			, "Perfect Forwarding"
			, "restorer http://stackoverflow.com/questions/2552839/which-c-standard-library-wrapper-functions-do-you-use"
			, "write end begin for std; http://stackoverflow.com/questions/2552839/which-c-standard-library-wrapper-functions-do-you-use"
			, "write a make string template make_string.h"
			, "string literal R("")"
			, "state machine"
			, "std::rotate rotate.h"
			, "Non-modifying sequence operations: http://en.cppreference.com/w/cpp/algorithm"
			, "Modifying sequence operations: http://en.cppreference.com/w/cpp/algorithm"
			, "Partitioning operations: http://en.cppreference.com/w/cpp/algorithm"
			, "Sorting operations: http://en.cppreference.com/w/cpp/algorithm"
			, "Binary search operations (on sorted ranges): http://en.cppreference.com/w/cpp/algorithm"
			, "Set operations (on sorted ranges): http://en.cppreference.com/w/cpp/algorithm"
			, "Heap operations: http://en.cppreference.com/w/cpp/algorithm"
			, "Minimum/Maximum operations: http://en.cppreference.com/w/cpp/algorithm"
			, "Numeric operations: http://en.cppreference.com/w/cpp/algorithm"
			, "C library qsort and bsearch: http://en.cppreference.com/w/cpp/algorithm"
			, "std::packaged_task: http://en.cppreference.com/w/cpp/thread/packaged_task"
			, "std::bind: http://en.cppreference.com/w/cpp/utility/functional/bind"
			, "Instead of doing runtime polymorphism you can work around it to avoid using pointers. See: runtime_polymorphism_workaround.h Note: this is part of avoid using raw pointers advice from some video"
        };
        
        for(auto item : tasks) {
            m_data.push_back(item);
        }
    }
    
    void add(const std::string& item) {
        m_data.push_back(item);
    }
    
    void get(unsigned long index) const {
        std::cout<< m_data[index];
    }
    
    unsigned long size() {return m_data.size();}
    
private:
    std::vector<std::string> m_data;
};

class Roulette {
public:
    Roulette() {
        srand(time(0));
    }
    
    int spin(unsigned long max) {
        int result = rand() % max + 0;
        return result;
    }
};
