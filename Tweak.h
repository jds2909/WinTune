#pragma once

#include <string>
#include <unordered_map>

class Tweak
{
public:

	struct selectionOption
	{
		unsigned int value;
		std::string label;
		std::string description;
	};

	std::string getRecVal() const { return m_recommendedValue; }

	std::string getId() const { return m_id; }

	std::string getName() const { return m_name; }

	std::string getType() const { return m_type; }

	std::string getCurrVal() const { return m_currentValue; }

	std::string getDesc() const { return m_description; }

	const std::vector<selectionOption>& getOptions() { return m_selectionValues; }

	Tweak(
		const std::string& id,
		const std::string& name,
		const std::string& description,
		const std::string& category,
		const std::string& riskLevel,
		const std::string& currentValue,
		const std::string& recommendedValue,
		const std::string& type,
		const std::vector<selectionOption>& selectionValues
	);

	void printDetails() const;

private:
	std::string m_id;
	std::string m_name;
	std::string m_description;
	std::string m_category;
	std::string m_riskLevel;
	std::string m_currentValue;
	std::string m_recommendedValue;
	std::string m_type;
	std::vector<selectionOption> m_selectionValues;
};