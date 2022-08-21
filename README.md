---
title: "Black-Scholes Model with C++"
author: "ABDOUL OUDOUSS DIAKITE"
date: "21 August,2022"
output:
  html_document: 
    toc: yes
    fig_caption: yes
    keep_md: yes
    fig_width: 10
    fig_height: 10
  word_document: 
    toc: yes
  pdf_document: 
    toc: yes
    latex_engine: lualatex
always_allow_html: true
---

## R Markdown

The Black-Scholes model, also known as the Black-Scholes-Merton (BSM) model, is one of the most important concepts in modern financial theory. This mathematical equation estimates the theoretical value of derivatives based on other investment instruments, taking into account the impact of time and other risk factors. Developed in 1973, it is still regarded as one of the best ways for pricing an options contract.

You can see the black and scholes equation and for more information you can follow this [link](https://en.wikipedia.org/wiki/Black%E2%80%93Scholes_model) :


$$\frac{\partial V}{\partial t} + \frac{1}{2}\sigma^2S^2\frac{\partial^2 V}{\partial S^2}+rS\frac{\partial V}{\partial S}-rV = 0$$
