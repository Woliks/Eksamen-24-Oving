import std;

class Person {
private:
	std::string navn;
	std::string adresse;
	std::string tlf;
public:
	Person(std::string navn, std::string adresse, std::string tlf);
};

class Ansatt :
	public Person
{
private:
	std::string stilling;
	bool deltid;
public:
	Ansatt(std::string navn);
};

class Student :
	public Person
{
private:
	std::string studentId;
	std::deque<std::unique_ptr<Emne>> emneListe;
public:
	Student() = default;
	Student(std::string navn, std::string adr, std::string tlf, std::string studentID);
};

class Institutt {
private:
	std::string navn;
	std::string adresse;
	std::deque<std::unique_ptr<Ansatt>> ansattListe;
	std::deque<std::unique_ptr<Emne>> emneListe;
	std::deque<std::unique_ptr<Student>> studentListe;
public:
	Institutt(std::string navn, std::string adresse);
	bool leggTilEmne(std::string emneKode, std::string emneNavn, std::string ansattnavn)
	{
		emneListe.push_back(std::unique_ptr<Emne>(new Emne(emneKode, emneNavn, Ansatt(ansattnavn))));
	}
	void skrivUtEmner();
	void registrerEmneForStudent(std::string emneKode, std::string studentnavn);
};

class Emne {
private:
	std::string emnekode;
	std::string emnenavn;
	std::string foreleser;
	std::deque<std::unique_ptr<Emne>> emneListe;
	std::deque<std::unique_ptr<Student>> studentListe;
public:
	Emne(std::string emnekode, std::string emnenavn, Ansatt foreleser);
};

class Karakter {
private:
	Student student;
	Emne emne;
	std::string karakter;
public:
	Karakter(Student student, Emne emne, std::string karakter);
};

int main()
{
	std::cout << "Hello World!\n";
}

