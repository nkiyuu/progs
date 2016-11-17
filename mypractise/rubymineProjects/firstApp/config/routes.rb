Rails.application.routes.draw do

  # get 'boards' => 'boards#index'
  # get 'boards/new' => 'boards#new'
  # get 'boards/:id' => 'boards#show'
  # get 'boards/:id/edit' => 'boards#edit'
  # post 'boards' => 'boards#create'
  # put 'boards/:id' => 'boards#update'
  # delete 'boards/:id' => 'boards#destroy'

  resources :boards do
    resources :comments, only:[:create, :destroy]
  end
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
