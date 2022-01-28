#include <iostream>
#include <vector>

using namespace std;

class AActor
{
public:
	AActor()
	{
		cout << "Actor Consturctor" << endl;
	}
	virtual ~AActor()
	{
		cout << "Actor Destructor" << endl;
	}

	virtual void Tick()
	{
		cout << "Actor Tick();" << endl;
	}

	int Gold = 10;
};

class ACubeActor : public AActor
{
public:
	ACubeActor()
	{
		cout << "Child Consturctor" << endl;
	}
	virtual ~ACubeActor()
	{
		cout << "Cube Destructor" << endl;
	}

	virtual void Tick() override
	{
		cout << "Cube Tick();" << endl;
	}
};

class AFloor : public ACubeActor
{
public:
	AFloor()
	{
		cout << "Floor Consturctor" << endl;
	}
	virtual ~AFloor()
	{
		cout << "Floor Destructor" << endl;
	}

	virtual void Tick() override
	{
		cout << "Floor Tick();" << endl;
	}
};

class MyEngine
{
public:
	MyEngine() {}
	virtual ~MyEngine() {}

	void SpawnActor(AActor* MakeActor)
	{
		ActorList.push_back(MakeActor);
	}

	void DestroyActor(AActor* DestroyedActor)
	{
		//for (auto iter = ActorList.begin(); iter != ActorList.end(); ++iter)
		//{
		//	if (*iter == DestroyedActor)
		//	{
		//		iter = ActorList.erase(iter);
		//	}
		//}

		ActorList.erase(find(ActorList.begin(), ActorList.end(), DestroyedActor));
	}

private:
	vector<AActor*> ActorList;
};

int main()
{
	AActor* object = new AFloor();

	object->Tick();

	delete object;
	object = nullptr;

	return 0;
}