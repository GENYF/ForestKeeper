<template>
  <v-app class="overflow-hidden">
    <v-app-bar app fixed color="#69cca2" dark>
      <v-icon class="mr-2">mdi-tree-outline</v-icon>

      <v-toolbar-title><strong>Forest Keeper</strong></v-toolbar-title>

      <div class="flex-grow-1"></div>

      <nav>
        <router-link to="/">홈</router-link>
        <router-link to="/app">앱</router-link>
        <router-link to="/wind">바람</router-link>
      </nav>
    </v-app-bar>

    <v-content>
      <router-view />
    </v-content>
  </v-app>
</template>

<style>
html {
  overflow: hidden;
}

html::-webkit-scrollbar {
  display: none;
}

nav a {
  text-decoration: none;
  font-weight: bold;
  font-size: 22px;
  color: #2c3e50;
  margin: 0 1vw;
  transition-duration: 200ms;
}

nav a:link,
nav a:visited {
  color: white;
}
nav a:hover {
  text-shadow: 0 5px 3px rgba(0, 0, 0, 0.2);
}
nav a.router-link-exact-active {
  padding-bottom: 3px;
  border-bottom: 2px solid white;
  text-shadow: 0 5px 3px rgba(0, 0, 0, 0.2);
}
</style>
