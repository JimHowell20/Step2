#include "stdafx.h"
#include "Mesh.h"


CMesh::CMesh(void)
{
}


CMesh::~CMesh(void)
{
}


void CMesh::Draw()
{
	glBegin(GL_TRIANGLES);
	for (PTV v = m_triangles.begin(); v != m_triangles.end(); v++)
	{
		glNormal3dv(m_normals[v->n]);
		glVertex3dv(m_vertices[v->v]);
	}
	glEnd();
}

void CMesh::AddTriangleVertex(int v, int n, int t)
{
	TV tv;
	tv.v = v;
	tv.n = n;
	tv.t = t;
	m_triangles.push_back(tv);
}

//
// Name :         CMesh::AddFlatQuad()
// Description :  Add a quadrangle to the triangle mesh.
//
void CMesh::AddFlatQuad(int a, int b, int c, int d, int n)
{
	// First triangle
	AddTriangleVertex(a, n, -1);
	AddTriangleVertex(b, n, -1);
	AddTriangleVertex(c, n, -1);

	// Second triangle
	AddTriangleVertex(a, n, -1);
	AddTriangleVertex(c, n, -1);
	AddTriangleVertex(d, n, -1);
}

//
// Name :         CMesh::AddQuad()
// Description :  Add a quadrangle to the triangle mesh with no 
//                assumption of flatness.
//
void CMesh::AddQuad(int a, int b, int c, int d)
{
	// First triangle
	AddTriangleVertex(a, a, -1);
	AddTriangleVertex(b, b, -1);
	AddTriangleVertex(c, c, -1);

	// Second triangle
	AddTriangleVertex(a, a, -1);
	AddTriangleVertex(c, c, -1);
	AddTriangleVertex(d, d, -1);
}