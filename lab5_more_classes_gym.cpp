using namespace std;

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

// constants
const double BASIC_RATE = 28.50,
			PREMIUM_RATE = 60.00;
// report width constants
const char SPACE 		= ' ';
const char HYPHEN		= '-';
const int ID_WIDTH 		= 8;
const int NAME_WIDTH 	= 18;
const int TYPE_WIDTH	= 6;
const int VISITS_WIDTH 	= 8;
const int RATE_WIDTH 	= 6;

struct Member {
	static int 	total_visits,	// count all visits from members
				active_members,	// total members active in my gym
				last_id;		// id assigned to newest member
	int id;			// id of this member
	string name;	// name of this member
	char type;		// type of member (B = basic, P = premium)
	int visits;		// visits by this member
	
	Member(string name, char type) {
		this->name = name;
		this->type = type;
		active_members++;
		id = last_id++;
	}
	
	~Member() {
		active_members--;
	}
};

// protoypes
void visit(Member*);
void printMember(Member*);

// Define static variables
int Member::total_visits = 0;
int Member::active_members = 0;
int Member::last_id = 100000;

int main() {
	vector<Member*> members;
	Member *oprah = new Member("Oprah Winfrey", 'P');
	Member *fluffy = new Member("Fluffy Iglesias", 'P');
	Member *charlie = new Member("Charlie Sheen", 'B');
	Member *bill = new Member("BIll Gates", 'B');
	
	cout << left << setw(NAME_WIDTH) << setfill(SPACE) << "Member";
	cout << left << setw(TYPE_WIDTH) << setfill(SPACE) << "Type" << endl;
	
	cout << left << setw(NAME_WIDTH - 2) << setfill(HYPHEN) << "";
	cout << left << setw(2) << setfill(SPACE) << "";
	cout << left << setw(TYPE_WIDTH - 2) << setfill(HYPHEN) << "";
	cout << left << setw(2) << setfill(SPACE) << "";
	cout << endl;
	
	cout << left << setw(NAME_WIDTH) << setfill(SPACE) << oprah->name;
	cout << left << setw(TYPE_WIDTH) << setfill(SPACE) << oprah->type << endl;
	cout << left << setw(NAME_WIDTH) << setfill(SPACE) << fluffy->name;
	cout << left << setw(TYPE_WIDTH) << setfill(SPACE) << fluffy->type << endl;
	cout << left << setw(NAME_WIDTH) << setfill(SPACE) << charlie->name;
	cout << left << setw(TYPE_WIDTH) << setfill(SPACE) << charlie->type << endl;
	cout << left << setw(NAME_WIDTH) << setfill(SPACE) << bill->name;
	cout << left << setw(TYPE_WIDTH) << setfill(SPACE) << bill->type << endl;
	
//	cout << oprah->name << " " << oprah->type << endl;
//	cout << fluffy->name << " " << fluffy->type << endl;
//	cout << charlie->name << " " << charlie->type << endl;
//	cout << bill->name << " " << bill->type << endl;
	
	cout << "Total members " << Member::active_members << endl << endl;
	
	delete charlie;
	charlie = nullptr;
	
	srand(time(NULL));
	int oprah_random = rand() % 15 + 5;
	int fluffy_random = rand() % 15 + 5;
	int bill_random = rand() % 15 + 5;
	
	for(int i = 0; i < oprah_random; i++){
		visit(oprah);
	}
	for(int i = 0; i < fluffy_random; i++){
		visit(fluffy);
	}
	for(int i = 0; i < bill_random; i++){
		visit(bill);
	}
	
	cout << left << setw(ID_WIDTH) << setfill(SPACE) << "ID";
	cout << left << setw(NAME_WIDTH) << setfill(SPACE) << "MEMBER";
	cout << left << setw(VISITS_WIDTH) << setfill(SPACE) << "VISITS";
	cout << left << setw(BASIC_RATE) << setfill(SPACE) << "RATE" << endl;
	cout << left << setw(ID_WIDTH - 2) << setfill(HYPHEN) << "";
	cout << left << setw(2) << setfill(SPACE) << "";
	cout << left << setw(NAME_WIDTH - 2) << setfill(HYPHEN) << "";
	cout << left << setw(2) << setfill(SPACE) << "";
	cout << left << setw(VISITS_WIDTH - 2) << setfill(HYPHEN) << "";
	cout << left << setw(2) << setfill(SPACE) << "";
	cout << left << setw(RATE_WIDTH) << setfill(HYPHEN) << "";
	cout << endl;
	printMember(oprah);
	printMember(fluffy);
	printMember(bill);
	
	cout << "\nTotal visits for gym " << Member::total_visits << endl;
	cout << "Total members " << Member::active_members << endl;
	
	return 0;
}

void visit(Member* member) {
	member->visits++;
	member->total_visits++;
}

void printMember(Member* member){
	cout << left << setw(ID_WIDTH) << setfill(SPACE) << member->id;
	cout << left << setw(NAME_WIDTH) << setfill(SPACE) << member->name;
	cout << left << setw(VISITS_WIDTH) << setfill(SPACE) << member->visits;
	cout << "$" << left << setw(BASIC_RATE) << setfill(SPACE) << fixed << showpoint << setprecision(2);
	if(member->type == 'B')
	{
		cout << BASIC_RATE;
	}
	else if(member->type == 'P')
	{
		cout << PREMIUM_RATE;
	}
	cout << endl;
}
