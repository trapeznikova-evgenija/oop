#include "CShapesRecorder.h"


bool CShapesRecorder::CreateTriangle()
{
	//������������ ������ �������� ������
	return true;
}


CShapesRecorder::CShapesRecorder(istream & in, ostream & out) :
	m_input(in),
	m_output(out),
	m_actionMap({
		 { "triangle", [this](istream & in)
					   {
						 return CreateTriangle();
					   }
		 },
		{"rectangle", [this](istream & in)
					   {
						   return CreateTriangle();
					   }
		}
		})
{
};


