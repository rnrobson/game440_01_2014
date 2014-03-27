struct Message
{
	std::string message;
	MessageType type;

	Message(std::string _message, MessageType _type) : message(_message), type(_type) 
	{
	}
};


enum MessageType
{
	Team,
	Public,
	Whisper
};