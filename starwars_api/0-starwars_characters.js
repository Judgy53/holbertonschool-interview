#!/usr/bin/node
const request = require('request');
const filmEndpoint = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

async function fetchCharacterName (url) {
  return new Promise((resolve, reject) => {
    request(url, (err, _, body) => {
      if (err) reject(err);

      resolve(JSON.parse(body).name);
    });
  });
}

request(filmEndpoint, async (err, _, body) => {
  if (err) throw err;

  const characters = await Promise.all(JSON.parse(body).characters.map(fetchCharacterName));

  characters.forEach((c) => console.log(c));
});
