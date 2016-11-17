Rails.application.routes.draw do
  get 'tweets/index'

  get 'tweets/show'

  get 'tweets/new'

  post "tweets" => "tweets#create"

  get 'users/index'
  get 'users/show/:username' => "users#show"

  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end