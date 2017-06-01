import { Component } from '@angular/core';

export class Hero {
    id: number;
    name: string;
}

const HEROS: Hero[] = [
        {id: 11, name: 'Mr. Nice'},
        {id: 12, name: 'Narco'}
];

@Component({
  selector: 'my-app',
  template: `
    <h1>{{title}}</h1>
    <h2>{{hero.name}} details!</h2>
    <div><label>id: </label>{{hero.id}}</div>
    <div>
      <label>name: </label>
      <input [(ngModel)]="hero.name" placeholder="name">
    </div>
    `
})

export class AppComponent {
    title = 'Tour of Heros';
    hero: Hero = {
         id: 1,
         name: 'Windstorm'
    };
}
