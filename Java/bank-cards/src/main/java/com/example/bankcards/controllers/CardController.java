package com.example.bankcards.controllers;

import com.example.bankcards.models.Card;
import com.example.bankcards.models.CardsResponse;
import com.example.bankcards.services.CardService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController("/cards")
public class CardController {
    @Autowired
    private CardService cardService;

    @GetMapping("/all")
    public ResponseEntity<CardsResponse> retrieveAllCards() {
        return ResponseEntity.ok(CardsResponse.builder().cards(cardService.retrieveAllCards()).build());
    }

    @GetMapping("/{number}")
    public ResponseEntity<Card> getCard(@PathVariable("number") final String number) {
        return ResponseEntity.ok(cardService.getCard(number));
    }

    @PostMapping("/")
    public ResponseEntity<Card> saveCard(@RequestBody final Card card) {
        return ResponseEntity.ok(cardService.addCard(card));
    }

    @PutMapping("/{number}")
    public ResponseEntity<Card> updateCard(@RequestBody final Card card, @PathVariable("number") final String number) {
        return ResponseEntity.ok(cardService.updateCard(number, card));
    }

    @DeleteMapping("/{number}")
    public ResponseEntity<String> deleteCard(@PathVariable("number") final String number) {
        cardService.deleteCard(number);
        return ResponseEntity.ok("ok");
    }

    @GetMapping("/holder/{holder}")
    public ResponseEntity<CardsResponse> retrieveCardsByHolder(@PathVariable("holder") final String holder) {
        return ResponseEntity.ok(CardsResponse.builder().cards(cardService.retrieveCardsByHolder(holder)).build());
    }

    @GetMapping("/{expirationMonth}/{expirationYear}")
    public ResponseEntity<CardsResponse> retrieveCardsByExpiration(@PathVariable("expirationMonth") final Integer expirationMonth,
                                                                   @PathVariable("expirationYear") final Integer expirationYear) {
        return ResponseEntity.ok(CardsResponse.builder().cards(cardService.retrieveCardsByExpiration(expirationMonth, expirationYear)).build());
    }
}
