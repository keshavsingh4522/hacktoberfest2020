package com.example.bankcards.models;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

import java.io.Serializable;

@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
@Document(collection = "Card")
public class Card implements Serializable {
    @Id
    private String number;
    private String holder;
    private Integer expirationMonth;
    private Integer expirationYear;
}
