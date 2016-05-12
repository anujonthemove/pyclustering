#include "container/adjacency_list.hpp"

#include <string>
#include <stdexcept>


namespace container {

adjacency_list::adjacency_list(const adjacency_list & another_matrix) {
    m_adjacency = another_matrix.m_adjacency;
}


adjacency_list::adjacency_list(adjacency_list && another_matrix) {
    m_adjacency = std::move(another_matrix.m_adjacency);
}


adjacency_list::adjacency_list(const size_t node_amount) : m_adjacency(node_amount) { }


adjacency_list::~adjacency_list(void) { }


size_t adjacency_list::size(void) const { return m_adjacency.size(); }


void adjacency_list::set_connection(const size_t node_index1, const size_t node_index2) {
    m_adjacency[node_index1].insert(node_index2);
}


void adjacency_list::erase_connection(const size_t node_index1, const size_t node_index2) {
    m_adjacency[node_index1].erase(node_index2);
}


bool adjacency_list::has_connection(const size_t node_index1, const size_t node_index2) const {
    const std::unordered_set<size_t> & node_neighbors = m_adjacency[node_index1];
    if (node_neighbors.find(node_index2) != node_neighbors.end()) {
        return true;
    }

    return false;
}


void adjacency_list::get_neighbors(const size_t node_index, std::vector<size_t> & node_neighbors) const {
    node_neighbors.resize(m_adjacency[node_index].size());
	std::copy(m_adjacency[node_index].begin(), m_adjacency[node_index].end(), node_neighbors.begin());
}


adjacency_list & adjacency_list::operator=(const adjacency_list & another_collection) {
    if (this != &another_collection) {
        m_adjacency = another_collection.m_adjacency;
    }

    return *this;
}


adjacency_list & adjacency_list::operator=(adjacency_list && another_collection) {
    if (this != &another_collection) {
        m_adjacency = std::move(another_collection.m_adjacency);
    }

    return *this;
}

}