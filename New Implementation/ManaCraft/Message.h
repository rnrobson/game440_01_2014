enum MessageType
{
	Team,
	Global,
	Whisper
};

struct Message
{
	std::string message;
	MessageType type;

	Message(std::string _message, MessageType _type) : message(_message), type(_type) 
	{
	}
};