class File
{
public:
	File(string name) : m_name(name) {};
	virtual ~File() {};
	virtual string name() const { return m_name; }
	virtual void open() const = 0;
	virtual void redisplay() const { cout << "refresh the screen"; }

private:
	string m_name;
};

class TextMsg : public File
{
public:
	TextMsg(string name) : File(name) {};
	~TextMsg() { cout << "Destroying " << File::name() << ", a text message\n"; }
	virtual void open() const { cout << "open text message"; }
};

class Video : public File
{
public:
	Video(string name, int runTime) : File(name), m_runTime(runTime) {};
	~Video() { cout << "Destroying " << File::name() << ", a video\n"; }
	virtual void open() const { cout << "play " << m_runTime << " second video"; }
	virtual void redisplay() const { cout << "replay video"; }

private:
	int m_runTime;
};

class Picture : public File
{
public:
	Picture(string name) : File(name) {};
	~Picture() { cout << "Destroying the picture " << File::name() << endl; }
	virtual void open() const { cout << "show picture"; }
};