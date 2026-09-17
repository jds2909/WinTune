#include "Tweak.h"

#include <iostream>

Tweak::Tweak
(
	const std::string& id,
	const std::string& name,
	const std::string& description,
	const std::string& category,
	const std::string& riskLevel,
	const std::string& currentValue,
	const std::string& recommendedValue
)
	: m_id(id),
	m_name(name),
	m_description(description),
	m_category(category),
	m_riskLevel(riskLevel),
	m_currentValue(currentValue),
	m_recommendedValue(recommendedValue)
{

}

void Tweak::printDetails() const
{
	std::cout << "ID: " << m_id << ".\n";
	std::cout << "Name: " << m_name << ".\n";
	std::cout << "Description: " << m_description << ".\n";
	std::cout << "Category: " << m_category << ".\n";
	std::cout << "Risk Level: " << m_riskLevel << ".\n";
	std::cout << "Category: " << m_currentValue << ".\n";
	std::cout << "Risk Level: " << m_recommendedValue << ".\n";
}