/*
Animal Shelter:
An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first out"
basis. Peopme must adopt either the "oldest" of all animals at the shelter, or they can select 
whether they would preer a dog or a cat. They cannot select which specific animal they would like.
Create the data structures to maintain this system, and implement operations such as enqueue,
dequeueAny, dequeueDog, dequeueCat. You may use the build-in LinkedList data structure.
*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<queue>

using namespace std;

enum animalBreed { dog, cat, unknown };

struct animal{
	string name;
	animalBreed breed;
	int timeStamp;
	animal(string name = "", animalBreed breed = animalBreed::unknown, int timeStamp = 0){
		this->name = name;
		this->breed = breed;
		this->timeStamp = timeStamp;
	}
	void setTimeStamp(int timeStamp){
		this->timeStamp = timeStamp;
	}
	int getTimeStamp(){
		return this->timeStamp;
	}
};

struct Dog:public animal{
	Dog(string name) : animal(name, dog) {};
};

struct Cat:public animal{
	Cat(string name) : animal(name, cat) {};
};

class AnimalShelter{
	private:
		queue<animal> dogs;
		queue<animal> cats;
		int timeStamp = 0;
	public:
		void enqueue(animal a);
		void dequeueAny();
		void dequeueCat();
		void dequeueDog();

};

void AnimalShelter::enqueue(animal a){
	if( a.breed != animalBreed::dog && a.breed != animalBreed::cat ){
		cout<<"Invalid breed of animal"<<endl;
		return;
	}else{
		timeStamp++;
		a.setTimeStamp(timeStamp);
		if(a.breed == animalBreed::dog)
			dogs.push(a);
		else if(a.breed == animalBreed::cat)
			cats.push(a);
	}
}

void AnimalShelter::dequeueAny(){
	// cout<<"Dogs size: "<<dogs.size()<<"\t Cats size: "<<cats.size()<<endl;
	if( dogs.size() == 0 && cats.size() == 0 )
		return;
	else if( dogs.size() == 0 ){
		dequeueCat();
	}else if( cats.size() == 0 ){
		dequeueDog();
	}else{
		if( cats.front().getTimeStamp() < dogs.front().getTimeStamp() )
			dequeueCat();
		else
			dequeueDog();
	}
}

void AnimalShelter::dequeueDog(){
	if( dogs.size() == 0 )
		return;
	else{
		cout<<"Dequed dog: "<<dogs.front().name<<endl;
		dogs.pop();
	}
}

void AnimalShelter::dequeueCat(){
	if( cats.size() == 0 )
		return;
	else{
		cout<<"Dequed cat: "<<cats.front().name<<endl;
		cats.pop();
	}
}

int main(){
	Dog d1("Dog 1");
	Dog d2("Dog 2");
	
	Cat c1("Cat 1");
	Dog d3("Dog 3");
	Cat c2("Cat 2");
	Dog d4("Dog 4");

	Cat c3("Cat 3");
	Cat c4("Cat 4");

	AnimalShelter aShelter;
	aShelter.enqueue(d1);
	aShelter.enqueue(d2);
	aShelter.enqueue(c1);
	aShelter.enqueue(d3);
	aShelter.enqueue(c2);
	aShelter.enqueue(d4);
	aShelter.enqueue(c3);
	aShelter.enqueue(c4);

	aShelter.dequeueAny();
	aShelter.dequeueCat();
	aShelter.dequeueAny();
	aShelter.dequeueAny();
	aShelter.dequeueAny();
	aShelter.dequeueDog();
	aShelter.dequeueAny();

}