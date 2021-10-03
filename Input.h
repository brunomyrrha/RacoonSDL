#ifndef INPUT_H
#define INPUT_H
class Input
{
public:
	Input(bool* mGameIsRunning);
	~Input();
	void Update();
private:
	bool* mGameIsRunning;
};
#endif // !INPUT_H

