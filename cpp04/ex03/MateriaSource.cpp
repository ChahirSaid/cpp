/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:23:16 by schahir           #+#    #+#             */
/*   Updated: 2025/12/21 14:06:56 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
    std::cout << "a [Materia Source] has been constructed (default)" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
    std::cout << "a [Materia Source] has been constructed (copy)" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
    for (int i = 0; i <4; i++)
    {
        if (_materias[i])
            delete _materias[i];
    }
    for (int i=0;i<4;i++)
    {
        if(other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
    std::cout << "a [Materia Source] has been assigned" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i=0;i<4; i++)
    {
        if(_materias[i])
            delete _materias[i];
    }
    std::cout << "a [Materia Source] has been destroyed" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return ;
    for (int i= 0; i <4; i++)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = m->clone();
            delete m;
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i=0 ; i<4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
    
}