package com.example.bankcards.repositories;

import com.example.bankcards.models.Card;
import org.springframework.data.mongodb.repository.MongoRepository;

import java.util.List;

public interface CardRepository extends MongoRepository<Card, String> {
    public List<Card> findAllByHolder(final String holder);

    public List<Card> findAllByExpirationMonthAndExpirationYear(final Integer expirationMonth, final Integer expirationYear);
}
