int mystrlen(const char* str)
{
	int i = -1;
	while (str[++i]);
	return i;
}

void mystrcpy(char*& destination, const char* source)
{
	if (source == nullptr) return;

	delete[] destination;

	int length = mystrlen(source);

	destination = new char[length + 1]; // '\0'
	for (int i = 0; i < length; i++)
	{
		destination[i] = source[i];
	}
	destination[length] = '\0';
}
