#pragma once
#include <string>
#include <exception>
#include <iostream>
using namespace std;

class CFlightCompException : public exception {
public:
    virtual void Show() const = 0;
    virtual ~CFlightCompException() {}
};

class CCompStringException : public CFlightCompException {
    string msg;
public:
    explicit CCompStringException(const string& m) : msg(m) {}
    void Show() const override { cout << msg << endl; }
};

class CCompLimitException : public CFlightCompException {
    int limit;
    string msg;
public:
    explicit CCompLimitException(int lim, const string& m = "") : limit(lim), msg(m) {}
    void Show() const override {
        if (!msg.empty()) cout << msg << endl;
        else cout << "Index out of range. Limit " << limit << endl;
    }
};

class CCompFileException : public CFlightCompException {
    string file;
    string msg;
public:
    explicit CCompFileException(const string& f, const string& m = "") : file(f), msg(m) {}
    void Show() const override {
        if (!msg.empty()) cout << msg << endl;
        else cout << "File error with " << file << endl;
    }
};
