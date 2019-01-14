#pragma once


// VectorSkill

class VectorSkill : public CWnd
{
	DECLARE_DYNAMIC(VectorSkill)

public:
	VectorSkill();
	virtual ~VectorSkill();
	void WriteVector();

protected:
	DECLARE_MESSAGE_MAP()
};


