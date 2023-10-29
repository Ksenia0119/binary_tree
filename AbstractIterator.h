#pragma once

//@author Maltseva K.V.
template<class T>
// ����������� ����� ��������
class Iterator {
public:
    //��������� �������� ��������,�� ������� ���
    virtual T& operator*() const = 0;
    //������� � ���������� �������� ���������
    virtual Iterator<T>& operator++() = 0;
    //���������� ������� �������� � ������ � ���������� true,
    //���� ��� ��������� �� ���� � ��� �� �������
    virtual bool operator==(const Iterator<T>& other) const = 0;
    //���������� ������� �������� � ������ � ���������� true,
   //���� ��� �� ��������� �� ���� � ��� �� �������
    virtual bool operator!=(const Iterator<T>& other) const = 0;
    virtual ~Iterator() {}
};
////����������� ����� ������������
//template<class T>
//class Iterable {
//public:
//    //������ ���������
//    virtual Iterator<T>& begin() const = 0;
//    //����� ���������
//    virtual Iterator<T>& end() const = 0;
//   // virtual ~Iterable() {}
//};
