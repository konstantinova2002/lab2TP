#include "Element.h"

Element* Element::GetNext() { return Next; };

void Element::SetNext(Element* Next) { this->Next = Next; }

Element* Element::GetPrev() { return Prev; };

void Element::SetPrev(Element* Prev) { this->Prev = Prev; };

ROUTE* Element::GetInformationROUTE() { return InformationROUTE; };

void Element::SetInformationROUTE(ROUTE* InformationROUTE) { this->InformationROUTE = InformationROUTE; };

int Element::GetNumRoute() { return NumRoute; };

void Element::SetNumRoute(int NumRoute) { this->NumRoute = NumRoute; };

Element::Element() {
	Next = nullptr;
	Prev = nullptr;
	InformationROUTE = nullptr;
	NumRoute = 0;
}

Element::Element(int NumRoute) {
	Next = nullptr;
	Prev = nullptr;
	InformationROUTE = nullptr;
	this->NumRoute = NumRoute;
}

Element::Element(const Element& other) {
	this->Next = other.Next;
	this->Prev = other.Prev;
	this->InformationROUTE = other.InformationROUTE;
	this->NumRoute = other.NumRoute;
}

