/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfpp.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:50:39 by Rustam            #+#    #+#             */
/*   Updated: 2020/01/05 20:05:39 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef TINYOBJLOADER_IMPLEMENTATION
# define TINYOBJLOADER_IMPLEMENTATION
#endif

#include "tiny_obj_loader.h"

int main(int argc, char **argv)
{
	std::vector<tinyobj::material_t> 	materials;
	std::vector<tinyobj::shape_t>		shapes;
	tinyobj::attrib_t					attributes;
	std::string							warning;
	std::string							error;

	bool ret = tinyobj::LoadObj(&attributes, &shapes, &materials, &warning, &error, argv[1]);

	if (!warning.empty())
  		std::cout << warning << std::endl;
	if (!error.empty())
		std::cerr << error << std::endl;
	if (!ret)
  		exit(1);

	for (size_t s = 0; s < shapes.size(); s++)
	{
		size_t index_offset = 0;
		for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++)
		{
			int fv = shapes[s].mesh.num_face_vertices[f];

    		for (size_t v = 0; v < fv; v++)
			{
      			tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
      			tinyobj::real_t vx = attributes.vertices[3*idx.vertex_index+0];
      			tinyobj::real_t vy = attributes.vertices[3*idx.vertex_index+1];
      			tinyobj::real_t vz = attributes.vertices[3*idx.vertex_index+2];
      			tinyobj::real_t nx = attributes.normals[3*idx.normal_index+0];
      			tinyobj::real_t ny = attributes.normals[3*idx.normal_index+1];
      			tinyobj::real_t nz = attributes.normals[3*idx.normal_index+2];
      			tinyobj::real_t tx = attributes.texcoords[2*idx.texcoord_index+0];
      			tinyobj::real_t ty = attributes.texcoords[2*idx.texcoord_index+1];
			}
    		index_offset += fv;
			shapes[s].mesh.material_ids[f];
  		}
	}
}
