#pragma once

#include <string>

class Tweak
{
public:
	Tweak(
		const std::string& id,
		const std::string& name,
		const std::string& description,
		const std::string& category,
		const std::string& riskLevel,
		const std::string& currentValue,
		const std::string& recommendedValue
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
};