// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : maxPower(mp), bitField(mp)
{
}

// конструктор копирования
TSet::TSet(const TSet &s) : maxPower(s.maxPower), bitField(s.bitField)
{
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : maxPower(bf.GetLength()), bitField(bf)
{
  /*BitField(-1)*/
}

//преобразование типа к TBitField
TSet::operator TBitField()
{
  TBitField temp( this->bitField );
  return temp;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
  return maxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
  return bitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
  bitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
  bitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
  bitField = s.bitField;
  maxPower = s.maxPower;
  return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
  return bitField == s.bitField;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
  return bitField != s.bitField;
}

TSet TSet::operator+(const TSet &s) // объединение
{
  TSet temp (bitField | s.bitField);
  return temp;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
  TSet temp (bitField);
  temp.bitField.SetBit(Elem);
  return temp;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
  TSet temp (bitField);
  temp.bitField.ClrBit(Elem);
  return temp;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
  TSet temp (bitField & s.bitField);
  return temp;
}

TSet TSet::operator~(void) // дополнение
{
  TSet temp (~bitField);
  return temp;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
  // формат ввода 0 1 4...
  // для прекращения ввода введите любой символ не являющийся цифрой или пробелом
  int temp;
  for (int i = 0; i<s.GetMaxPower();i++)
  {
	istr >> temp;
	s.InsElem(temp);
  }
  return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
  for (int i = 0; i < s.GetMaxPower(); i++)
    if ( s.IsMember(i) )
      ostr << i << ' ';
  return ostr;
}