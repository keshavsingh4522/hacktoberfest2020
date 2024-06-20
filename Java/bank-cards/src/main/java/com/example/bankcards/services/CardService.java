package com.example.bankcards.services;

import com.example.bankcards.models.Card;
import com.example.bankcards.repositories.CardRepository;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Slf4j
@Service
public class CardService {
    @Autowired
    private CardRepository cardRepository;

    public List<Card> retrieveAllCards() {
        return cardRepository.findAll();
    }

    public Card getCard(final String number) {
        Optional<Card> cardOptional = cardRepository.findById(number);
        Card card = null;
        if (cardOptional.isPresent()) {
            card = cardOptional.get();
        }
        return card;
    }

    public Card addCard(final Card card) {
        return cardRepository.save(card);
    }

    public Card updateCard(final String number, final Card card) {
        Optional<Card> cardOptional = cardRepository.findById(number);
        Card cardPrev = null;
        if (cardOptional.isPresent()) {
            cardPrev = cardOptional.get();
            cardPrev.setExpirationMonth(card.getExpirationMonth());
            cardPrev.setExpirationYear(card.getExpirationYear());
            cardPrev.setHolder(card.getHolder());
            return cardRepository.save(cardPrev);
        } else {
            return cardRepository.save(card);
        }
    }

    public void deleteCard(final String number) {
        cardRepository.deleteById(number);
    }

    public List<Card> retrieveCardsByHolder(final String holder) {
        return cardRepository.findAllByHolder(holder);
    }

    public List<Card> retrieveCardsByExpiration(final Integer expirationMonth, final Integer expirationYear) {
        return cardRepository.findAllByExpirationMonthAndExpirationYear(expirationMonth, expirationYear);
    }
}
