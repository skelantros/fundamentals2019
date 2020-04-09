#include "DictPair.h"

DictPair::DictPair(const String& w, const String& t) : _word(w), _translate(t) {}

const String& DictPair::word() const { return _word; }
const String& DictPair::translate() const { return _translate; }

bool DictPair::operator==(const DictPair& right) const { return _word == right._word; }
bool DictPair::operator<(const DictPair& right) const { return _word < right._word; }

bool DictPair::operator!=(const DictPair& right) const { return !(*this == right); }
bool DictPair::operator<=(const DictPair& right) const { return (*this == right) || (*this < right); }
bool DictPair::operator>=(const DictPair& right) const { return !(*this < right); }
bool DictPair::operator>(const DictPair& right) const { return !(*this <= right); }

std::ostream& operator<<(std::ostream& stream, const DictPair& dp)
{
	stream << dp.word() << " - " << dp.translate();
	return stream;
}

std::istream& operator>>(std::istream& stream, DictPair& dp)
{
	String tmp_str;
	stream >> tmp_str;
	int split_idx = tmp_str.find('$');
	char* word; char* translate;
	if (split_idx == -1)
	{
		word = new char[tmp_str.length() + 1];
		memcpy_s(word, tmp_str.length() + 1, tmp_str.str(), tmp_str.length() + 1);
		dp = DictPair(word);
		delete[] word;
	}
	else
	{
		word = new char[split_idx + 1];
		memcpy_s(word, split_idx, tmp_str.str(), split_idx);
		word[split_idx] = 0;
		translate = new char[tmp_str.length() - split_idx];
		memcpy_s(translate, tmp_str.length() - split_idx, tmp_str.str() + split_idx + 1, tmp_str.length() - split_idx);
		dp = DictPair(word, translate);
		delete[] word;
		delete[] translate;
	}


	return stream;
}