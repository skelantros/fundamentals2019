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
	if (split_idx == -1)
		dp = DictPair(tmp_str);
	else
	{
		tmp_str[split_idx] = 0;
		dp = DictPair(tmp_str.str(), tmp_str.str() + split_idx + 1);
	}
	return stream;
}

DictPair& DictPair::operator=(DictPair&& src)
{
	_word = std::move(src._word);
	_translate = std::move(src._translate);
	return *this;
}

DictPair::DictPair(DictPair&& src) :
	_word(std::move(src._word)),
	_translate(std::move(src._translate)) {}