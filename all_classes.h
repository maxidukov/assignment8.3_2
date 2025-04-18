#ifndef ALL_CLASSES_H
#define ALL_CLASSES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

enum Problem {Warning, Error, Fatal};

class Observer{
public:
    virtual void update(const std::string& message, Problem pr) = 0;
    virtual void onError(const std::string& message) {};
    virtual void onFatalError(const std::string& message) {};
    virtual void onWarning(const std::string& message) {std::cout << "This is a warning! " << message << std::endl;};
};

class SourceOfTrouble{
private:
    std::vector<Observer*> observers_;
public:
    void AddObserver(Observer* observer) {
        observers_.push_back(observer);
    }
    void RemoveObserver(Observer* observer) {
        auto it = std::remove(observers_.begin(), observers_.end(), observer);
        observers_.erase(it, observers_.end());
    }
    void Notify(const std::string& message, Problem pr){
        for(auto& obs : observers_)
            obs->update(message, pr);
    }
    void warning(const std::string& message) {Notify(message, Warning);}
    void error(const std::string& message) {Notify(message, Error);}
    void fatalError(const std::string& message) {Notify(message, Fatal);}
};

class ObserverForWarnings : public Observer{
    void update(const std::string& message, Problem pr) override{
        if(pr == Warning){ onWarning(message);}
    }
    // void onWarning(const std::string& message) override {std::cout << "This is a warning! " << message << std::endl;};
};

class ObserverForErrors : public Observer{
    std::string file_name_ = "file.txt";
public:
    ObserverForErrors(const std::string& file_name = "file.txt"): file_name_(file_name) {}
    void update(const std::string& message, Problem pr) override{
        if(pr == Error){ onError(message);}
    }
    void onError(const std::string& message) override {
        std::cout << "Error! Pinting to file" << std::endl;
        std::ofstream fout;
        fout.open(file_name_);
        fout << message << std::endl;
        fout.close();

    }
};
class ObserverForFatal : public Observer{
    std::string file_name_ = "file.txt";
public:
    ObserverForFatal(const std::string& file_name = "file.txt"): file_name_(file_name) {}
    void update(const std::string& message, Problem pr) override{
        if(pr == Fatal){ onFatalError(message);}
    }
    void onFatalError(const std::string& message) override {
        std::cout << "This is fatal error: " << message << ", printing to file" << std::endl;
        std::ofstream fout;
        fout.open(file_name_);
        fout << message << std::endl;
        fout.close();

    }
};



#endif // ALL_CLASSES_H
