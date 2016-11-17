class Board < ApplicationRecord
  has_many :comments, dependent: :destroy

  validates :title, presence: true, length: { in: 4..127}
  validates :editor, presence: true, length: { in: 1..200}
end
