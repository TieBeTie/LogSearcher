// src/filters/PredicateBuilder.hpp
#pragma once
#include "predicates/Predicate.hpp"
#include "predicates/SourcePredicate.hpp"
#include "predicates/LogLevelPredicate.hpp"
#include "predicates/DescriptionPredicate.hpp"
#include "predicates/TargetPredicate.hpp"
#include "predicates/TimestampDurationPredicate.hpp"
#include <memory>
#include <vector>

class PredicateBuilder {
public:
    PredicateBuilder() = default;
    
    PredicateBuilder& withSource(const std::string& source) {
        addPredicate<SourcePredicate>(source);
        return *this;
    }
    
    PredicateBuilder& withTimeRange(const Timestamp& start, const Timestamp& end) {
        addPredicate<TimestampDurationPredicate>(start, end);
        return *this;
    }

    PredicateBuilder& and() {
        m_operations.push_back(LogicalOp::AND);
        return *this;
    }
    
    PredicateBuilder& or() {
        m_operations.push_back(LogicalOp::OR);
        return *this;
    }
    
    PredicateBuilder& not() {
        m_operations.push_back(LogicalOp::NOT);
        return *this;
    }

    std::unique_ptr<Predicate> build() {
        if(m_operands.empty()) {
            throw std::logic_error("No conditions specified");
        }
        
        while(!m_operations.empty()) {
            applyLastOperation();
        }
        
        return std::move(m_operands.back());
    }

private:
    enum class LogicalOp { AND, OR, NOT };
    std::vector<std::unique_ptr<Predicate>> m_operands;
    std::vector<LogicalOp> m_operations;
    
    template<typename T, typename... Args>
    void addPredicate(Args&&... args) {
        m_operands.push_back(
            std::make_unique<T>(std::forward<Args>(args)...)
        );
    }
    
    void applyLastOperation() {
        auto op = m_operations.back();
        m_operations.pop_back();
        
        switch(op) {
            case LogicalOp::AND: break;
            case LogicalOp::OR: break;
            case LogicalOp::NOT: break;
        }
    }
};