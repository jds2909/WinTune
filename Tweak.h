#pragma once

#include <string>

class Tweak
{
public:

	std::string getRecVal() const { return m_recommendedValue; }

	std::string getId() const { return m_id; }

	std::string getName() const { return m_name; }

	std::string getType() const { return m_type; }

	std::string getCurrVal() const { return m_currentValue; }

	Tweak(
		const std::string& id,
		const std::string& name,
		const std::string& description,
		const std::string& category,
		const std::string& riskLevel,
		const std::string& currentValue,
		const std::string& recommendedValue,
		const std::string& type
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
};