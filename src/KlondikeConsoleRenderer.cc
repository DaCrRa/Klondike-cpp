/*
 * KlondikeConsoleRenderer.cpp
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <KlondikeConsoleRenderer.h>

#include <iostream>
#include <iterator>
#include <assert.h>

void KlondikeConsoleRenderer::render() {
	renderStock();
	renderFoundations();
	renderTableau();
}

void KlondikeConsoleRenderer::renderStock() {
	assert(stock != nullptr);
	std::cout << "Rendering stock..." << std::endl;
}

void KlondikeConsoleRenderer::renderFoundations() {
	assert(foundations != nullptr);
	for (std::vector<Foundation>::iterator it = foundations->begin(); it != foundations->end(); ++it) {
		renderFoundation(it.base());
	}
}

void KlondikeConsoleRenderer::renderFoundation(Foundation* f) {
	assert(f != nullptr);
	std::cout << "Rendering a foundation..." << std::endl;
}

void KlondikeConsoleRenderer::renderTableau() {
	assert(tableau != nullptr);
	for (std::vector<TableauPile>::iterator it = tableau->begin(); it != tableau->end(); ++it) {
		renderTableauPile(it.base());
	}
}

void KlondikeConsoleRenderer::renderTableauPile(TableauPile* tp) {
	assert(tp != nullptr);
	std::cout << "Rendering a tableau pile..." << std::endl;
}
