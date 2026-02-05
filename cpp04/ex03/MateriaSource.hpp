/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:21:49 by schahir           #+#    #+#             */
/*   Updated: 2025/12/20 03:26:44 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALSOURCE_HPP
#define MATERIALSOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _materias[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource& operator=(const MateriaSource &other);
        ~MateriaSource();
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif