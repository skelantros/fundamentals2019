#pragma once
#pragma once


template <typename Key, typename Value>
class DictPairT {
	Key _word;
	Value _translate;
public:
	DictPairT(const Key& w = Key(), const Value& t = Value()) : _word(w), _translate(t) {}
	DictPairT(const DictPairT& src) : _word(src._word), _translate(src._translate) {}
		
	const Key& key() const { return _word; }
	const Value& value() const { return _translate; }

	bool operator< (const DictPairT& right) const { return _word < right._word; }
	bool operator<=(const DictPairT& right) const { return _word <= right._word; }
	bool operator> (const DictPairT& right) const { return _word > right._word; }
	bool operator>=(const DictPairT& right) const { return _word >= right._word; }
	bool operator==(const DictPairT& right) const { return _word == right._word; }
	bool operator!=(const DictPairT& right) const { return _word != right._word; }

	DictPairT& operator=(DictPairT& src)
	{
		_word = src._word;
		_translate = src._translate;
		return *this;
	}

	DictPairT& operator=(DictPairT&& src)
	{
		_word = std::move(src._word);
		_translate = std::move(src._translate);
		return *this;
	}
	DictPairT(DictPairT&& src) :
		_word(std::move(src._word)),
		_translate(std::move(src._translate)) {}

};